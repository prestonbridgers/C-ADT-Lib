#!/usr/bin/bash

cd ./doc
make html
cd ..
scp -r doc/build/html/* prestonbridgers.com:~/www/website/html/cdsl
