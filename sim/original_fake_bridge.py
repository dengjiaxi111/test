#!/usr/bin/env python3
"""直接调用隔离副本中的原fake桥，不另定义fake坐标语义。"""
import sys
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src/my_navigation/fake_vel_transform'))
from fake_vel_transform.node import main
if __name__=='__main__':main()
