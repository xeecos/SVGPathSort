#include <node.h>
#include <node_buffer.h>
#include <v8.h>
#include "path.h"
using v8::Context;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::Array;
using v8::String;
using v8::Value;
static Paths paths(0);
void clear(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope scope(isolate);
    paths.clear();
    args.GetReturnValue().Set(v8::Integer::New(isolate, 1));
}
void addPath(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope scope(isolate);
    Local<Array> points = Local<Array>::Cast(args[0]);
    int len = points->Length() / 3;
    vector<Point> path(len);
    for (int i = 0; i < len; i++)
    {
        path[i].type = (PointType)points->Get(i)->Int32Value();
        path[i].x = points->Get(i + 1)->NumberValue();
        path[i].y = points->Get(i + 2)->NumberValue();
    }
    paths.push_back(path);
    args.GetReturnValue().Set(v8::Integer::New(isolate, path.size()));
}
void sortPaths(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope scope(isolate);
    vector<int> order(0);
    vector<int> start(0);
    optimize_path(paths, order, start);
    Local<Array> arr = v8::Array::New(isolate);
    Local<Array> orders = v8::Array::New(isolate);
    Local<Array> starts = v8::Array::New(isolate);
    for (int i = 0; i < order.size(); i++)
    {
        orders->Set(i, v8::Number::New(isolate, order[i]));
    }
    for (int i = 0; i < start.size(); i++)
    {
        starts->Set(i, v8::Number::New(isolate, start[i]));
    }
    arr->Set(0, orders);
    arr->Set(1, starts);
    args.GetReturnValue().Set(arr);
}
void init(v8::Local<v8::Object> exports)
{
    NODE_SET_METHOD(exports, "sortPaths", sortPaths);
    NODE_SET_METHOD(exports, "addPath", addPath);
}

NODE_MODULE(binding, init);