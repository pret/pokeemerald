addrs =  sorted([0xdd7360,
                 0xdd87c0,
                 0xdd8ee0,
                 0xdd8780,
                 0xdd90e0,
                 0xdd9718,
                 0xdd9080,
                 0xdd98b4,
                 0xdd9e58,
                 0xdd9874,
                 0xdda02c,
                 0xdda63c,
                 0xdd9fec,
                 0xdda840,
                 0xddae40,
                 0xdda800,
                 0xddb020,
                 0xddb2c4,
                 0xddafe0,
                 0xddb3e4])
for i, addr in enumerate(addrs[:-1]):
    print 'gUnknown_08{0:06X}:: @ 8{0:06X}'.format(addr)
    print '\t.incbin "baserom.gba", 0x{:06x}, 0x{:x}'.format(addr, addrs[i + 1] - addr)
    print ''
