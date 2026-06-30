#ifndef MPRPCAPPLICATION_H
#define MPRPCAPPLICATION_H

class MpRpcApplication {
public:
    static MpRpcApplication& Instance();
    static void Init(int argc, char** argv);
private:
    MpRpcApplication() {};
    MpRpcApplication(const MpRpcApplication&) = delete;
    MpRpcApplication& operator=(const MpRpcApplication&) = delete;
    MpRpcApplication(MpRpcApplication&&) = delete;
};

#endif