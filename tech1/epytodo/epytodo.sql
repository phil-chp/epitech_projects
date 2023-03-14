CREATE DATABASE IF NOT EXISTS `epytodo`;

USE `epytodo`;

CREATE TABLE IF NOT EXISTS `user`
(
    `id`         BIGINT        NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `email`      VARCHAR(255)  NOT NULL UNIQUE,
    `password`   VARCHAR(255)  NOT NULL,
    `name`       VARCHAR(255)  NOT NULL,
    `firstname`  VARCHAR(255)  NOT NULL,
    `created_at` TIMESTAMP     DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS `todo`
(
    `id`          INT          NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `title`       VARCHAR(255) NOT NULL,
    `description` VARCHAR(255) NOT NULL,
    `created_at`  TIMESTAMP    DEFAULT CURRENT_TIMESTAMP,
    `due_time`    DATETIME     NOT NULL,
    `status`      VARCHAR(255) DEFAULT 'not started',
    `user_id`     BIGINT,
    FOREIGN KEY (`user_id`) REFERENCES `user`(`id`) ON DELETE SET NULL
);
