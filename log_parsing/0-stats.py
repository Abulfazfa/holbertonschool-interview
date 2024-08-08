#!/usr/bin/python3
"""
Module parses and prints stats to stdout
"""


from sys import stdin

status_codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}

size = 0


