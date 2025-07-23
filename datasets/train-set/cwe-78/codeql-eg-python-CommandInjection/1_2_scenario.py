```python
import socket
import threading
import logging
import time

# Start an advanced server that listens on a specific port, handles multiple incoming connections simultaneously, 
# logs connection details, and shuts down gracefully on a termination signal.
def start_advanced_server(port, max_connections):
    # Create a TCP/IP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    
    # Set up logging for the server to keep track of connections
    logging.basicConfig(level=logging.INFO)
    
    #-copilot next line-
```