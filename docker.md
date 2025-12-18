

```
docker run --rm -it -p 3000:3000 debian:trixie 
apt-get update
apt-get install -yq git
git clone https://gitlab.dpt-info.univ-littoral.fr/julien.dehos/add42.git
cd add42
cat package.list | xargs apt-get install -yq 
cmake -S . -B build
cmake --build build
./build/add42.out
```

