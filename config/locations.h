//Temp File write locations

#define TBR_LOCATION         "/tmp/total_bytes_received"
#define TBT_LOCATION         "/tmp/total_bytes_transmitted"
#define TBRS_LOCATION        "/tmp/total_bytes_received_per_second"
#define TBTS_LOCATION        "/tmp/total_bytes_transmitted_per_second"
#define BWT_LOCATION         "/tmp/total_throughput_bytes"
#define CONN_LOCATION        "/tmp/ss_conn_rate"
#define MEMFREE_LOCATION     "/tmp/mem_free"
#define MEMTOTAL_LOCATION    "/tmp/mem_total"
#define CPU_SUMMARY          "/tmp/cpu_summary"
#define ETH0_RXS_LOCATION    "/tmp/eth_0_rxs"
#define ETH0_TXS_LOCATION    "/tmp/eth_0_txs"
#define ETH0_TOTAL_LOCATION  "/tmp/eth_0_total"
#define ETH1_RXS_LOCATION    "/tmp/eth_1_rxs"
#define ETH1_TXS_LOCATION    "/tmp/eth_1_txs"
#define ETH1_TOTAL_LOCATION  "/tmp/eth_1_total"

//Proc locations

#define PROC_NET_DEV  "/proc/net/dev"
#define PROC_MEM_INFO "/proc/meminfo"
#define PROC_STAT_CPU "/proc/stat"

//PID LOCATIONS

#define NGINX_PID "/var/run/nginx.pid"
#define REDIS_PID_1 "/var/run/redis_6379.pid"
#define REDIS_PID_2 "/var/run/redis_6380.pid"
#define REDIS_PID_3 "/var/run/redis_6381.pid"
#define REDIS_PID_4 "/var/run/redis_6382.pid"
#define MYSQL_PID "/var/run/mysqld/mysqld.pid"

#define STEIN_LOG_PID         "/var/run/zmqToTCP/LOGS.pid"
#define UUID_PID        "/var/run/zmqToTCP/UUID.pid"
#define REDIS_PID       "/var/run/zmqToRedis/REDIS.pid"
#define FLUME_LOG_PID   "/var/run/flumeToTCP/LOGS.pid"
#define FLUME_UUID_PID  "/var/run/flumeToTCP/UUID.pid"
#define UDP_LOG_PID     "/var/run/udpToZMQ/LOGS.pid"
#define UDP_UUID_PID    "/var/run/udpToZMQ/UUID.pid"
#define UDP_REDIS_PID   "/var/run/udpToZMQ/REDIS.pid"
#define UDP_NUT_PID     "/var/run/nutcracker.pid"



//Serial Locations
#define SERIAL "/etc/dios/serial"
#define HOSTNAME "/etc/hostname"

//Encryption Keys
#define ENCODEDKEY "/etc/dios/encoded.key"
#define ENCODEDIV  "/etc/dios/encoded.iv"

//Monitoring Server

#define MONITORSERVERIP "/etc/monitoring_server/monitor/ip"
#define COMMANDPORT "/etc/monitoring_server/monitor/commandport"
#define LOCALEVENTPORT "/etc/monitoring_server/monitor/localeventport"
#define MONITORDATAPORT "/etc/monitoring_server/monitor/monitordataport"
#define LAN "/etc/monitoring_server/lan"
#define WAN "/etc/monitoring_server/wan"


//Location information

#define DATACENTERID "/etc/monitoring_server/datacenter/id"
#define ROLE "/etc/dios/role"
#define ACCOUNTID "/etc/dios/accountID"
#define PRIVATE   "/etc/dios/private"
#define PRIVATEDC "/etc/dios/datacenterID"
#define REDISMASTER "/etc/dios/redismaster/ip"
#define REDISPASS "/etc/dios/redismaster/auth"
#define ACCESSKEY "/etc/dios/private.rsa"


//Server Information
#define CORES "/etc/nginx/worker.processes"


#define ACK_COMMAND "00000000000000000"
#define ACK_SERIAL  "4444-4444-4444-4444"
#define BROADCAST_SERIAL "5555-5555-5555-5555"