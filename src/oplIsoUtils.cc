// thin cpp wrapper exposing iso2opl getGameId
// native C++ addons study
// by sarpt

#include "oplIsoUtils.h"

namespace oplIsoUtils {

  void getGameId(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();

    if (args.Length() < 2) {
      isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Wrong number of arguments - 2 necessary (string, boolean)")));
      return;
    } else if (!args[0]->IsString()) {
      isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "First argument is not a string")));
      return;
    } else if (!args[1]->IsBoolean()) {
      isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Second argument is not a boolean")));
      return;
    }

    v8::String::Utf8Value v8String(args[0]);
    std::string stdString(*v8String);

    char gameId[255];
    const char* fullName = stdString.c_str();
    int isBigEndian = args[1]->BooleanValue();

    s64 retval = GetGameID(fullName, isBigEndian, 1, gameId);
    if (retval <= 0) {
      isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Error processing file")));
      return;
    }

    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, gameId));
  }

  void init(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "getGameId", getGameId);
  }

  NODE_MODULE(node_oplIsoUtils, init)

}
