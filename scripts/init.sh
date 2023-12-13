#!/bin/bash

YELLOW='\033[1;33m'
ORANGE='\033[0;33m'
NC='\033[0m' # No Color
ITALICS='\e[3m'
NO_ITALICS='\e[0m'

# Absolute path to the west workspace directory
WEST_WORKSPACE_PATH=$(realpath $(dirname "$0")/../..)

echo -e "${YELLOW}--> Change working directory to ${ITALICS}${WEST_WORKSPACE_PATH}${NO_ITALICS}${NC}"
cd $WEST_WORKSPACE_PATH

if [ -d ".venv" ]; then
    echo -e "${ORANGE}--> Python virtual environment already exists${NC}"
else
    echo -e "${YELLOW}--> Create Python virtual environment${NC}"
    python3 -m .venv venv
fi

echo -e "${YELLOW}--> Activate Python Virtual Environment${NC}"
source .venv/bin/activate
pip install west
cd app

echo -e "${YELLOW}--> Update west dependencies using${NC}"
west update
pip install -r ../zephyr/scripts/requirements.txt
