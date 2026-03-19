

create database learnweb;

use learnweb;

create table users (
    id int auto_increment primary key,
    name varchar(16) not null,
    created_at timestamp default current_timestamp
);

create table hackers (
    id int auto_increment primary key,
    name varchar(16) not null,
    created_at timestamp default current_timestamp
);

