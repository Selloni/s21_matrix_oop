FROM ubuntu

RUN apt-get update && apt install -y gcc libgtest-dev libgmock-dev libtbb-dev make vim valgrind

# RUN apt-get update && \
#     apt-get install -y \
#       libboost-dev libboost-program-options-dev \
#       libgtest-dev \
#       cmake \
#     && \
#     cmake -DCMAKE_BUILD_TYPE=Release /usr/src/gtest && \
#     cmake --build . && \
#     mv lib*.a /usr/lib

COPY . /project

WORKDIR "/project"