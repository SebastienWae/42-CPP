from string import Template
import shutil
import argparse
import os

parser = argparse.ArgumentParser()
parser.add_argument("dst")
parser.add_argument("name")
parser.add_argument("files")
args = parser.parse_args()

src = os.path.abspath(os.path.dirname(__file__))

os.path.join(src, 'gitignore');

with open(os.path.join(src, ".gitignore"), "r") as gitignore:
  template = Template(gitignore.read())
  template = template.safe_substitute(project_name=args.name)
  with open(os.path.join(args.dst, ".gitignore"), "w") as new_gitignore:
    new_gitignore.write(template)

with open(os.path.join(src, "Makefile"), "r") as makefile:
  template = Template(makefile.read())
  template = template.safe_substitute(project_name=args.name, project_files=args.files)
  with open(os.path.join(args.dst, "Makefile"), "w") as new_makefile:
    new_makefile.write(template)

shutil.copyfile(os.path.join(src, ".clang-format"), os.path.join(args.dst, ".clang-format"))
shutil.copyfile(os.path.join(src, ".clang-tidy"), os.path.join(args.dst, ".clang-tidy"))
shutil.copyfile(os.path.join(src, ".clangd"), os.path.join(args.dst, ".clangd"))

files = args.files.split(" ")
for f in files:
  open(os.path.join(args.dst,f), 'w')
