```python
import socket
import threading

# Start a simple server that listens on a specific port and responds to incoming connections.
def start_server(port):
    # Create a TCP/IP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    #-copilot next line-
```