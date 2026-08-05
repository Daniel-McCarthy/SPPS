# See https://aka.ms/vscode-remote/devcontainer/base for more info.
FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

# Install system dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    curl \
    wget \
    git \
    python3 \
    python3-venv \
    python3-pip \
    p7zip-full \
    build-essential \
    unzip \
    && rm -rf /var/lib/apt/lists/*

# Ensure python3 points to python
RUN update-alternatives --install /usr/bin/python python /usr/bin/python3 1

# Set work directory
WORKDIR /workspace

# Install project python deps in a venv
RUN python3 -m venv /opt/venv
ENV PATH="/opt/venv/bin:${PATH}"

# Install python dependencies into venv
COPY requirements.txt /workspace/requirements.txt
RUN pip install --upgrade pip && pip install -r /workspace/requirements.txt

# Default entrypoint is shell
ENTRYPOINT ["/bin/bash"]
