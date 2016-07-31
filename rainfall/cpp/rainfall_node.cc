#include <node.h>
#include <v8.h>
#include "rainfall.h"

using namespace v8;

void AvgRainfall(const v8::FunctionCallbackInfo<v8::Value>& args) {
  Isolate* isolate = args.GetIsolate();

  Local<Number> retval = v8::Number::New(isolate, 0);
  args.GetReturnValue().Set(retval);
}

void init(Handle <Object> exports, Handle<Object> module) {
  // we'll register our functions here
  NODE_SET_METHOD(exports, "avg_rainfall", AvgRainfall);
}

NODE_MODULE(rainfall, init)
