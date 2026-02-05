# boot.py -- run on boot-up
# Mount external QSPI flash filesystem

import os
import machine

try:
    # QSPI flash is accessed via machine.Flash() with id=1
    # id=0 is internal flash, id=1 is external QSPI
    qspi = machine.Flash(start=0, len=32*1024*1024, id=1)
    
    # Try to mount the filesystem
    try:
        os.mount(qspi, '/qspi')
        print('External QSPI flash mounted at /qspi')
        os.chdir('/qspi')
    except:
        # Format if not formatted
        print('Formatting QSPI flash...')
        os.VfsLfs2.mkfs(qspi)
        os.mount(qspi, '/qspi')
        print('QSPI flash formatted and mounted at /qspi')
        os.chdir('/qspi')
        
except Exception as e:
    print(f'QSPI flash setup failed: {e}')
    print('Using internal flash instead')

