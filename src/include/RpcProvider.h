#ifndef RPCPROVIDER_H
#define RPCPROVIDER_H

#include <google/protobuf/service.h>

class RpcProvider{
public:
    void NotifyService(google::protobuf::Service* service);
    void Run();
private:
};

#endif