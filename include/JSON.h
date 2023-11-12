#pragma once

#include <map>
#include <memory>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

class Value {
public:
  virtual ~Value() = default;

  virtual void dump(std::string &stream) = 0;
};

class Null : public Value {
public:
  void dump(std::string &stream) override;
};

class Boolean : public Value {
  bool value = false;

public:
  void dump(std::string &stream) override;
};

class Number : public Value {
  std::variant<int64_t, uint64_t, double> value;

public:
  Number(uint64_t Num) : value(Num){};

  void dump(std::string &stream) override;
};

class String : public Value {
  std::string value;

public:
  void dump(std::string &stream) override;
};

class Array : public Value {
  std::vector<std::unique_ptr<Value>> values;

public:
  void dump(std::string &stream) override;
};

class Object : public Value {
  std::map<std::string, std::unique_ptr<Value>> values;

public:
  void insert(std::string_view key, std::unique_ptr<Value> value);

  void dump(std::string &stream) override;
};

extern std::unique_ptr<Object> json;
