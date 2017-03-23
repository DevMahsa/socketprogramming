Sometimes you need to open an special port that actually is open via ipv4 but not available in ipv6, you need to force the port to open for someone else with another unic ip address to see your commit. I've used this code to open 10051 port for the one of my users to see the zabbix dashboard in an especial ip address. 
Compatibility with IPv4 Nodes of RFC 3493
This code is a kind of dealing with the behaviour of AF_INET6 sockets. AF_INET (IPv4) sockets simply cannot and will not deal with anything IPv6.
This behavior may be overridden with the IPV6_V6ONLY socket option. Setting this option will cause the socket to only handle IPv6 and not allow anything IPv4.
