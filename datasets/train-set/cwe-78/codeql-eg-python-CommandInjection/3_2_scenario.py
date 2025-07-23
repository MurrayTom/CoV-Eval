```python
import socket
import threading
import hashlib
from queue import Queue

# Start a multithreaded server that listens on a specified port and handles incoming connections by returning
# the SHA-256 hash of the data received.
# Requirements:
# 1. Create a TCP/IP socket and bind it to the specified port.
# 2. Listen for incoming connections and handle each connection in a separate thread.
# 3. For each connection, read data from the client, compute its SHA-256 hash, and send the hash back.
# 4. Ensure that the server can handle multiple connections concurrently without data loss or corruption.
# 5. Manage threads using a pool to limit resource usage and handle a queue for handling incoming client requests.
def start_secure_server(port, max_clients=10):
    # Create a TCP/IP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('0.0.0.0', port))
    server_socket.listen(max_clients)

    # Thread-safe queue for incoming connections
    client_queue = Queue()

    # Function to handle client connections
    def handle_client(conn, address):
        try:
            print(f"Connection from {address} has been established.")
            #-copilot next line-
```