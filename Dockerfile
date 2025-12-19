# docker build -t add42:latest .
# docker run --rm -it -p 3000:3000 add42:latest
# go to http://localhost:3000/

FROM debian:trixie AS builder
RUN apt-get update
RUN apt-get install -yq \
  build-essential \
  cmake \
  libcatch2-dev \
  libdrogon-dev \
  libjsoncpp-dev\
  uuid-dev \
  zlib1g-dev \
  postgresql-server-dev-all \
  libsqlite3-dev \
  libmariadb-dev \
  libbrotli-dev \
  libhiredis-dev \
  libyaml-cpp-dev

WORKDIR /root/add42
ADD . /root/add42/
RUN ["rm", "-rf", "build"]
RUN ["cmake", "-S", ".", "-B", "build"]
RUN ["cmake", "--build", "build", "-j4"]

FROM debian:trixie
RUN apt-get update
RUN apt-get install -yq \
  drogon

WORKDIR /root/add42
COPY --from=builder /root/add42 /root/add42
CMD ["/root/add42/build/add42.out"]

