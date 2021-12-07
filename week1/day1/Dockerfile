FROM centos

WORKDIR /home

RUN yum update -y
RUN yum install epel-release -y
RUN dnf -y group install "Development Tools"
RUN yum -y install vim git gdb clang cscope zip curl htop iftop iotop tree

COPY . /home
