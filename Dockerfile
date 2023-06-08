ARG DISTR

# Container image that runs your code
FROM $DISTR

ARG USER_ID
ARG GROUP_ID

# Copies your code file from your action repository to the filesystem path `/` of the container
COPY script/build.sh /build.sh

RUN apt-get update \
    && apt-get install -y git \
    gear \
    hasher \
    hasher-priv \
    hasher-rich-chroot \
    hasher-rich-chroot-user-utils \
    rpm-utils \
    rpm-build \
    rpm-build-licenses \
    rpm-macros-cmake \
    rpm-macros-make \
    rpm-macros-generic-compat \
    apt-repo \
    apt-repo-tools \
    cmake \
    rpm-macros-cmake \
    cmake-modules \
    gcc \
    doxygen \
    sudo \
    && export CURRENT_PWD=`pwd` \
    && groupadd --gid $GROUP_ID test \
    && useradd --uid $USER_ID --gid $GROUP_ID -ms /bin/bash test \
    && groupadd sudo \
    && usermod -aG rpm test \
    && usermod -aG sudo root \
    && usermod -aG sudo test \
    && echo "root ALL=(ALL) NOPASSWD:ALL" | tee -a /etc/sudoers \
    && echo "test ALL=(ALL) NOPASSWD:ALL" | tee -a /etc/sudoers \
    && hasher-useradd test \
    && mkdir -p /app \
    && chown root:test /app \
    && chown root:test /build.sh \
    && chmod g+x /build.sh

ARG ARCH

RUN if [ "$ARCH" = "i386" ]; then \
       sed -i 's/gear-hsh/i586 gear-hsh/g' /build.sh; \
       sed -i 's/x86_64/i686/g' /build.sh; \
    fi

USER test
WORKDIR /app

# Code file to execute when the docker container starts up (`build.sh`)
ENTRYPOINT ["/build.sh"]

