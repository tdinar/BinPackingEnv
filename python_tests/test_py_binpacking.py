import sys
import os

# Add the build directory to the Python module search path
build_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'build'))
sys.path.insert(0, build_dir)

print(build_dir)

from py_binpacking import BinPackingEnv

# Initialize and test
env = BinPackingEnv()
print("Initial state:", env.get_state())
env.step()
print("State after step:", env.get_state())
env.reset()
print("State after reset:", env.get_state())
