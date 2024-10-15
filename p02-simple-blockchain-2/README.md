OpenSSL3 doesn't support RIPEMD-160 by default, to enable, add this

/etc/ssl/openssl.cnf
```
[openssl_init]
providers = provider_sect

# List of providers to load
[provider_sect]
default = default_sect
+legacy = legacy_sect

[default_sect]
activate = 1

+[legacy_sect]
+activate = 1
```
