#include <iostream>
#include <node.h>
using namespace v8;

void CallThis(const FunctionCallbackInfo<Value> & args) {
  Isolate * isolate = args.GetIsolate();
  Local<Function> cb = Local<Function>::Cast(args[0]);

  if (args.Length() >= 2) {
    Local<Value> argv[1] = {args[1]};
    cb->Call(Null(isolate), 1, argv);
    return;
  }
  cb->Call(Null(isolate), 0, nullptr);
  return;
}


void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "callthis", CallThis);
}

NODE_MODULE(callback, Init)
