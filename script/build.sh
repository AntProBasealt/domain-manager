#!/bin/bash -ex

#git clone https://github.com/AntProBasealt/domain-manager.git /123
chown -R test:test /app/
cd /app/ && gear-rpm -ba
