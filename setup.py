import setuptools
from numpy.distutils.core import setup, Extension


with open("README.md", "r", encoding="utf-8") as fh:
    long_description = fh.read()

#---------------------------------------------------------------------------  
ext1 = Extension(
    name='hawkroutines',
    sources=['Root/hawkroutines.f',
             'Root/weightandoptobs.f'],
    f2py_options=["--quiet"],
)

#--------------------------------------------------------------------------
setup(
    name='vbfcprw',
    version='0.1',
    ext_modules=[ext1],
    packages=['vbfcprw'],
    install_requires=["numpy", "pylorentz", "parton"],
    author="David Hohn",
    author_email="hohn.david@gmail.com",
    url="https://gitlab.cern.ch/FreiburgSchumacher/vbfcp/HLeptonsCPRW",
    description="wrapper for simplified CP reweighting using HAWK generator",
    long_description=long_description,
    long_description_content_type="text/markdown",
)

# manually this works too
# python -m numpy.f2py -c Root/*.f -m hawkroutines
# howto
# python setup.py build
# python setup.py bdist_wheel
# python setup.py install