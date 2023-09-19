#include "JSON.h"

void String::dump(std::string &stream) {
  std::string slash = "\"";
  stream += slash;
  stream += value;
  stream += slash;
}

void Object::insert(std::string_view key, std::unique_ptr<Value> value) {
  values.insert({std::string(key), std::move(value)});
}

void Object::dump(std::string &stream) {
  std::string slash = "\"";

  stream += "{";

  for (auto &kv : values) {
    stream += slash;
    stream += kv.first;
    stream += ":";
    kv.second->dump(stream);
    stream += ",";
  }

  stream += "}";
}

std::unique_ptr<Object> json = std::make_unique<Object>();
