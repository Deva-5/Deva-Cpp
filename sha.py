import hashlib

str= "Devakumar"

result=hashlib.md5(str.encode())

print("HexaDigest of Sha1:")

print(result.hexdigest())