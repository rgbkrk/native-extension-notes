#include <node.h>
using namespace v8;

void Add(const FunctionCallbackInfo<Value> & args) {
  Isolate * isolate = args.GetIsolate();

  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
      String::NewFromUtf8(isolate, "Wrong number of arguments")
    ));
    return;
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    return;
  }

  double value = args[0]->NumberValue() + args[1]->NumberValue();

  Local<Number> num = Number::New(isolate, value);

  args.GetReturnValue().Set(num);
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "add", Add);
}

NODE_MODULE(cmath, Init)
