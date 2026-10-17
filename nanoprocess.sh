
#!/bin/bash

echo "Running Processes:"
ps

echo "Top CPU Processes:"
ps aux --sort=-%cpu | head
