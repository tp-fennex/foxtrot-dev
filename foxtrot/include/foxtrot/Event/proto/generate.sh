#!/bin/bash

protoc -I=. --cpp_out=. event.proto
protoc -I=. --cpp_out=. header.proto

echo `pwd`