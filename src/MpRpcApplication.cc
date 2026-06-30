#include "MpRpcApplication.h"

MpRpcApplication& MpRpcApplication::Instance() {
    static MpRpcApplication app;
    return app;
}

void MpRpcApplication::Init(int argc, char** argv) {
    
}