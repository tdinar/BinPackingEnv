from env_wrapper import BinPackingWrapper
from agent import RandomAgent
from logger import BinPackingLogger

env = BinPackingWrapper()
agent = RandomAgent()
logger = BinPackingLogger()

EPISODE_ID = 1
STEPS = 5  # fixed number for now

env.reset()
for _ in range(STEPS):
    x, y, w, h = agent.act()
    env.step(x, y, w, h)

data = env.get_log_data()
logger.write_episode(EPISODE_ID, data)
print(f"Episode {EPISODE_ID} logged.")
