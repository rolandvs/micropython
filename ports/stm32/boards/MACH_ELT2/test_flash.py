"""
Test script for W25Q256JV QSPI Flash filesystem
Run this on your board after flashing firmware
"""

import os
import time
import gc

print("=" * 50)
print("W25Q256JV QSPI Flash Test Suite")
print("=" * 50)

def test_mount():
    """Test if flash is mounted"""
    print("\n[1/6] Testing mount...")
    try:
        files = os.listdir('/flash')
        print(f"✓ Flash mounted at /flash")
        print(f"  Files: {files}")
        return True
    except Exception as e:
        print(f"✗ Mount failed: {e}")
        return False

def test_write():
    """Test write operations"""
    print("\n[2/6] Testing write...")
    try:
        test_data = "Hello from QSPI Flash! " * 100
        with open('/flash/test_write.txt', 'w') as f:
            f.write(test_data)
        print(f"✓ Wrote {len(test_data)} bytes")
        return True
    except Exception as e:
        print(f"✗ Write failed: {e}")
        return False

def test_read():
    """Test read operations"""
    print("\n[3/6] Testing read...")
    try:
        with open('/flash/test_write.txt', 'r') as f:
            data = f.read()
        expected = "Hello from QSPI Flash! " * 100
        if data == expected:
            print(f"✓ Read {len(data)} bytes correctly")
            return True
        else:
            print(f"✗ Data mismatch!")
            return False
    except Exception as e:
        print(f"✗ Read failed: {e}")
        return False

def test_performance():
    """Test read/write speed"""
    print("\n[4/6] Testing performance...")
    try:
        # Write test
        block_size = 4096
        num_blocks = 100
        test_data = b'X' * block_size
        
        start = time.ticks_ms()
        with open('/flash/perf_test.bin', 'wb') as f:
            for i in range(num_blocks):
                f.write(test_data)
        write_time = time.ticks_diff(time.ticks_ms(), start)
        write_speed = (block_size * num_blocks) / (write_time / 1000) / 1024
        
        # Read test
        start = time.ticks_ms()
        with open('/flash/perf_test.bin', 'rb') as f:
            while f.read(block_size):
                pass
        read_time = time.ticks_diff(time.ticks_ms(), start)
        read_speed = (block_size * num_blocks) / (read_time / 1000) / 1024
        
        print(f"✓ Write speed: {write_speed:.2f} KB/s")
        print(f"✓ Read speed: {read_speed:.2f} KB/s")
        
        # Cleanup
        os.remove('/flash/perf_test.bin')
        return True
    except Exception as e:
        print(f"✗ Performance test failed: {e}")
        return False

def test_filesystem_info():
    """Display filesystem information"""
    print("\n[5/6] Filesystem info...")
    try:
        stat = os.statvfs('/flash')
        block_size = stat[0]
        total_blocks = stat[2]
        free_blocks = stat[3]
        
        total_kb = (block_size * total_blocks) / 1024
        free_kb = (block_size * free_blocks) / 1024
        used_kb = total_kb - free_kb
        
        print(f"✓ Total space: {total_kb:.2f} KB ({total_kb/1024:.2f} MB)")
        print(f"  Used space:  {used_kb:.2f} KB ({used_kb/1024:.2f} MB)")
        print(f"  Free space:  {free_kb:.2f} KB ({free_kb/1024:.2f} MB)")
        print(f"  Block size:  {block_size} bytes")
        return True
    except Exception as e:
        print(f"✗ Filesystem info failed: {e}")
        return False

def test_cleanup():
    """Cleanup test files"""
    print("\n[6/6] Cleaning up...")
    try:
        os.remove('/flash/test_write.txt')
        print("✓ Test files removed")
        return True
    except Exception as e:
        print(f"✗ Cleanup failed: {e}")
        return False

def run_all_tests():
    """Run all tests"""
    tests = [
        test_mount,
        test_write,
        test_read,
        test_performance,
        test_filesystem_info,
        test_cleanup
    ]
    
    results = []
    for test in tests:
        results.append(test())
    
    print("\n" + "=" * 50)
    print(f"Results: {sum(results)}/{len(results)} tests passed")
    print("=" * 50)
    
    if all(results):
        print("\n✓ All tests PASSED! Your QSPI flash is working correctly.")
    else:
        print("\n✗ Some tests FAILED. Check connections and configuration.")
    
    return all(results)

# Run tests automatically when imported
if __name__ == '__main__':
    run_all_tests()
