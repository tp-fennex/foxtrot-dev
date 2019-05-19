#!/bin/bash

protoc -I=. --cpp_out=. event.proto

echo `pwd`