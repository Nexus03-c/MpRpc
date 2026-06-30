#include <string>
#include <iostream>
#include "user.pb.h"
#include "MpRpcApplication.h"
#include "RpcProvider.h"

class UserService: public proto_user::UserServiceRpc {
public:
    bool Login(std::string &name, std::string &pwd) {
        std::cout<<"doing local service::Login"<<std::endl;
        std::cout<<"name:"<<name<<" pwd:"<<pwd<<std::endl;
        return true;
    }

    void Login(google::protobuf::RpcController* controller,
                       const ::proto_user::LoginRequest* request,
                       ::proto_user::LoginResponse* response,
                       ::google::protobuf::Closure* done)
    {
        std::string name = request->name();
        std::string pwd = request->pwd();

        bool res = Login(name, pwd);

        proto_user::ResultCode *code = response->mutable_result();
        code->set_errcode(1);
        code->set_errmsg("");
        response->set_success(res);

        done->Run();
    }
};

int main(int argc, char **argv) {
    MpRpcApplication::Init(argc, argv);

    RpcProvider provider;
    provider.NotifyService(new UserService());

    provider.Run();

    return 0;
}