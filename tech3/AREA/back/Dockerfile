FROM node:alpine

WORKDIR /app

COPY package*.json ./

RUN set -eux \
    & apk add \
        --no-cache \
        nodejs \
        yarn \
    yarn


RUN yarn install

# COPY . .

CMD ["yarn", "start"]
