source ~/emsdk/emsdk/emsdk_env.sh
cd build
emcmake cmake ..
emmake make
cp -rf . ../deploy/
cd ..
cd deploy
sudo heroku container:login
sudo heroku container:push web -a hello-emscripten-sdl
sudo heroku container:release web -a hello-emscripten-sdl

