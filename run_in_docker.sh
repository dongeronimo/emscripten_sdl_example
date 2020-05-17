source ~/emsdk/emsdk/emsdk_env.sh
cd build
emcmake cmake ..
emmake make
cd ..
sudo docker container stop emscripten-hello-world || true
sudo docker container rm emscripten-hello-world -f || true
sudo docker image rm geronimodesenvolvimentos/emscripten-hello-world-sdl:latest -f
sudo docker build --no-cache -t geronimodesenvolvimentos/emscripten-hello-world-sdl:latest .
sudo docker run --name emscripten-hello-world -p 10000:80 -d geronimodesenvolvimentos/emscripten-hello-world-sdl
sudo docker container prune -f
sudo docker image prune -f
