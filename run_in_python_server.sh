source ~/emsdk/emsdk/emsdk_env.sh
cd build
emcmake cmake ..
emmake make
python3 -m http.server
