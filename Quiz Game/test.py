import time

# Physics Constants
y = 100.0   # Initial height in meters
v = 0.0     # Initial velocity (m/s)
g = -9.81   # Gravity (m/s^2)
dt = 0.1    # Time step (seconds)

print("Starting physics simulation...")
for step in range(50):
    v += g * dt  # Update velocity
    y += v * dt  # Update position
    
    if y <= 0:   # Bounce mechanics
        y = 0
        v = -v * 0.8  # Lose 20% energy on bounce
        
    print(f"Time: {step*dt:.1f}s | Height: {y:.2f}m | Velocity: {v:.2f}m/s")
    time.sleep(0.05)
