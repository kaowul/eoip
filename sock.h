#ifndef EOIP_SOCK_H_
#define EOIP_SOCK_H_

#include <arpa/inet.h>
#include <netinet/in.h>

#include "eoip.h"
#include "eoip-proto.h"

union packet {
  uint16_t header;
  uint8_t  buffer[BUFFER_SIZE];
  struct ip ip;
  struct eoip_packet eoip;
  struct eoip6_packet eoip6;
};

int bind_sock(int *fd, sa_family_t af, in_port_t proto,
              const struct sockaddr *addr, const socklen_t addr_len);

void sock_listen(sa_family_t af, int fd, int tap_fd, int tid,
                 struct sockaddr *laddr, socklen_t laddrlen);

void populate_sockaddr(sa_family_t af, in_port_t port, const char *addr,
              struct sockaddr_storage *dst, socklen_t *addrlen);

#endif // EOIP_SOCK_H_
