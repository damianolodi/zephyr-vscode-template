```bash
cd project_dir
python3 -m venv .venv
source .venv/bin/activate
pip install west
cd app
west init -l .
west update
pip install -r ../zephyr/scripts/requirements.txt
```