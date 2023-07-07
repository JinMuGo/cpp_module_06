FROM alpine:latest

RUN apk update && apk add make g++

WORKDIR /app
COPY . /app
RUN make && make fclean
