FROM alpine as builder

RUN apk add --no-cache bash clang make libc-dev binutils build-base

COPY . /build
WORKDIR /build

RUN make -C /build NAME=player && make clean

FROM alpine as player

COPY --from=builder /build/player /app/player
WORKDIR /app

CMD  ./player
