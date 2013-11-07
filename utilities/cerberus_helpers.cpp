#include "../../Common/Includes/locations.h"
#include "cerberus_helpers.hpp";



using CryptoPP::AutoSeededRandomPool;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::exit;
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;
using CryptoPP::AES;
using CryptoPP::CTR_Mode;
using namespace std;

//nproc

std::string md5value(std::string message){
    CryptoPP::Weak::MD5 hash;
    std::string output;
    byte digest[ CryptoPP::Weak::MD5::DIGESTSIZE ];
    

    hash.CalculateDigest( digest, (byte*) message.c_str(), message.length() );
    CryptoPP::HexEncoder encoder;
    encoder.Attach( new CryptoPP::StringSink( output ) );
    encoder.Put( digest, sizeof(digest) );
    encoder.MessageEnd();
    std::transform(output.begin(), output.end(), output.begin(), ::tolower);
    
    return output;

}

string core_count(){

    string current_cores;
    FILE * fp;
    char path[PATH_MAX];//
    fp = popen("nproc", "r");

    if (fp == NULL) {
           // WARNING("Couldn't access ss utility.  Try apt-get install iproute2\n");
            syslog(LOG_PERROR, "Couldn't access nproc.  Try apt-get install iproute2\n");
            current_cores = "8";
        }



    while(fgets( path, PATH_MAX, fp ) != NULL){
       current_cores =  path;
    }


    

    pclose(fp);
    current_cores.erase(std::remove(current_cores.begin(), current_cores.end(), '\n'), current_cores.end());
    return current_cores;

}

//test
void fix_utf8_string(std::string& str)
{
    std::string temp;
    utf8::replace_invalid(str.begin(), str.end(), back_inserter(temp));
    str = temp;
}

vector<string> read_tmp_stats(std::string filename, vector<string> output) {
     std::ifstream in(filename);
     std::string line;

     while (std::getline(in, line))
         output.push_back(line);

     return output;
}



string read_tmp_stats_oneline(std::string filename){
    std::ifstream in(filename);
    std::string line, backup;
    backup = "0";

    if(std::getline(in, line))
        if(!line.empty()){
            fix_utf8_string(line);
            return line;   
        }
        else {
            fix_utf8_string(backup);
            return backup; 
        }
         
    else {
        fix_utf8_string(backup);
       return backup;//changed for now 
   }
    
}

int write_to_disk_general(long int value, string file){

    ofstream tmpOutfile;
    tmpOutfile.open(file);
    if (tmpOutfile.is_open()){

        tmpOutfile << value << endl;
        tmpOutfile.close();

        return 1;

    } else {
        return 0;
    }
}

int write_to_disk_string(string value, string file){

    ofstream tmpOutfile;
    tmpOutfile.open(file);
    if (tmpOutfile.is_open()){

        tmpOutfile << value << endl;
        tmpOutfile.close();

        return 1;

    } else {
        return 0;
    }   //
}

string bit_conversion_sec(long double bits){
    string bandwidth_string;

    long double kilobit;
    long double megabit;
    long double gigabit;

    kilobit = 1024;
    megabit = kilobit * 1024;
    gigabit = megabit * 1024;

    if(bits < kilobit){
        bandwidth_string = to_string(bits) + " b/s";
    } else if(bits < megabit){
        bandwidth_string = to_string(bits / kilobit) + " Kb/s";
    } else if(bits < gigabit){
        bandwidth_string = to_string(bits / megabit) + " Mb/s";
    }

    return bandwidth_string;
}



string byte_conversion(long double byte){
    string bandwidth_string;


    long double kilobyte;
    long double megabyte;
    long double gigabyte;
    long double terabyte;

    kilobyte = 1024;
    megabyte = kilobyte * 1024;
    gigabyte = megabyte * 1024;
    terabyte = gigabyte * 1024;

    if(byte < kilobyte){
        bandwidth_string = to_string(byte);
        bandwidth_string +=  " B ";
    } else if(byte < megabyte){
        bandwidth_string = to_string(byte / kilobyte) + " KB ";
    } else if(byte < gigabyte){
        bandwidth_string = to_string(byte / megabyte) + " MB ";
    } else if(byte < terabyte){
        bandwidth_string = to_string(byte / gigabyte) + " GB ";
    } else {
        bandwidth_string = to_string(byte / terabyte) + " TB ";
    }


    return bandwidth_string;
}

string encrypt(string message, string encodedKey, string encodedIv){

    string key, iv, output;


    StringSource ssk(encodedKey, true /*pump all*/,
    new HexDecoder(
        new StringSink(key)
    ) // HexDecoder
   ); // StringSource

    StringSource ssv(encodedIv, true /*pump all*/,
    new HexDecoder(
        new StringSink(iv)
    ) // HexDecoder
   ); // StringSource

    CTR_Mode< AES >::Encryption enc;
    enc.SetKeyWithIV(reinterpret_cast<const byte*>(key.c_str()), key.size(),reinterpret_cast<const byte*>(iv.c_str()));

    StringSource(message, true, 
      new StreamTransformationFilter(enc,
        new StringSink(output)
      ) // StreamTransformationFilter      
    ); // StringSource
    
    return output;
  }

  string decrypt(string message, string encodedKey, string encodedIv){

    CTR_Mode< AES >::Decryption d;
    string key, iv, output;
    


    StringSource ssk(encodedKey, true /*pump all*/,
    new HexDecoder(
        new StringSink(key)
    ) // HexDecoder
   ); // StringSource

    StringSource ssv(encodedIv, true /*pump all*/,
    new HexDecoder(
        new StringSink(iv)
    ) // HexDecoder
   ); // StringSource
    
    d.SetKeyWithIV(reinterpret_cast<const byte*>(key.c_str()), key.size(),reinterpret_cast<const byte*>(iv.c_str()));
    
    StringSource s(message, true, 
      new StreamTransformationFilter(d,
        new StringSink(output)
      ) // StreamTransformationFilter
    ); // StringSource

    return output;
  }
/* Open/create the file named in 'pidFile', lock it, optionally set the
   close-on-exec flag for the file descriptor, write our PID into the file,
   and (in case the caller is interested) return the file descriptor
   referring to the locked file. The caller is responsible for deleting
   'pidFile' file (just) before process termination. 'progName' should be the
   name of the calling program (i.e., argv[0] or similar), and is used only for
   diagnostic messages. If we can't open 'pidFile', or we encounter some other
   error, then we print an appropriate diagnostic and terminate. */

int createPidFile(pid_t pid, std::string  pidFile)
{
    ofstream pid_write;
    std::string pid_location ="/var/run/"+pidFile+".pid";

    pid_write.open(pid_location.c_str());
    pid_write << pid;
    pid_write.close();




    return 1;
}
