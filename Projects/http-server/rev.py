import struct

# TODO: Double-click these variables in Ghidra and update their values!
# They are found in the data section starting at address 0x00404090.
KEY_0 = 0x00000000  # Replace with value at DAT_00404090
KEY_1 = 0x00000000  # Replace with value at DAT_00404094
KEY_2 = 0x00000000  # Replace with value at DAT_00404098
KEY_3 = 0x00000000  # Replace with value at DAT_0040409c

DELTA = 0x9E3779B9  # Unsigned equivalence of -0x61c88647

# The hardcoded targets from FUN_004012bd
targets = [
    (0x424901af, 0xa811c4ec),  # Block 1
    (0xbe966699, 0x41b6ef04),  # Block 2
    (0xc38bf13c, 0xba3a1c1e)   # Block 3
]

def decrypt_block(v0, v1):
    # Recreate the accumulated sum state after exactly 32 (0x20) iterations
    # Each loop adds -0x61c88647 (which is DELTA in unsigned 32-bit arithmetic)
    num_rounds = 0x20
    current_sum = (DELTA * num_rounds) & 0xFFFFFFFF
    
    for _ in range(num_rounds):
        # Reverse the second equation step (modifying local_10 / v1)
        v1 = (v1 - (((v0 >> 5) + KEY_3) ^ ((v0 * 0x10) + KEY_2) ^ (current_sum + v0))) & 0xFFFFFFFF
        
        # Reverse the first equation step (modifying local_c / v0)
        v0 = (v0 - (((v1 >> 5) + KEY_1) ^ ((v1 * 0x10) + KEY_0) ^ (current_sum + v1))) & 0xFFFFFFFF
        
        # Decrement the sum tracker state exactly how it accumulated during encryption
        current_sum = (current_sum - DELTA) & 0xFFFFFFFF
        
    return v0, v1

# Run inverse cipher path tracking across the 3 target blocks
flag_bytes = bytearray()
for v0, v1 in targets:
    orig_v0, orig_v1 = decrypt_block(v0, v1)
    # Package numbers back into little-endian strings
    flag_bytes.extend(struct.pack("<I", orig_v0))
    flag_bytes.extend(struct.pack("<I", orig_v1))

# Replace the old print line with these two:
print(f"Plaintext string representation: {flag_bytes.decode('utf-8', errors='ignore')}")
print(f"Raw Byte Array (Copy the characters or escape sequences): {list(flag_bytes)}")
print(f"Hex-encoded representation: {flag_bytes.hex()}")
