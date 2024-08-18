[](http://dockone.io/article/6051)

# docker
https://docs.docker.com/get-started/overview/

## docker install
- docker
https://docs.docker.com/engine/install/debian/
- nvidia docker
https://docs.nvidia.com/datacenter/cloud-native/container-toolkit/install-guide.html#docker

- (docker env)I am using Ubunu 20.04 and I found daemon.json in /var/snap/docker/current/config/daemon.json
https://stackoverflow.com/questions/43689271/wheres-dockers-daemon-json-missing 
issue: standard_init_linux.go:228: exec user process caused: exec format error

## docker usage
```bash
# list local docker images
sudo docker images
# test docker status by demo
sudo docker run hello-world
# show docker env
sudo docker info
# restart docker env
sudo systemctl restart docker
# delete local images
docker system prune -a --volumes https://stackoverflow.com/questions/44785585/docker-how-to-delete-all-local-docker-images
```

## dockerfile
```dockerfile
ARG BASE_IMAGE=nvcr.io/nvidia/l4t-base:r32.4.3
FROM ${BASE_IMAGE}
COPY ./packages/ros_entrypoint.sh /ros_entrypoint.sh
RUN echo 'source ${ROS_ROOT}/setup.bash' >> /root/.bashrc 
RUN chmod +x /ros_entrypoint.sh
ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["bash"]
WORKDIR /
```

## workflow
Step 1: Create a file named Dockerfile
Step 2: Add instructions in Dockerfile
Step 3: Build dockerfile to create image
Step 4: Run image to create container
https://www.youtube.com/watch?v=LQjaJINkQXY
https://github.com/wsargent/docker-cheat-sheet#dockerfile
