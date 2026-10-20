import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/dengjiaxi/simulation_seu/test/install/fake_vel_transform'
