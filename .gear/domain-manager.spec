%define _unpackaged_files_terminate_build 1

Name: domain-manager
Version: 0.1.0
Release: alt1

Summary: Domain-manager - domain creation software, based on Samba.
License: GPLv2+
Group: Other
Url: https://github.com/AntProBasealt/domain-manager

BuildRequires: cmake
BuildRequires: rpm-macros-cmake
BuildRequires: cmake-modules
BuildRequires: gcc

BuildRequires: doxygen

Source0: %name-%version.tar

%description
Domain creator

%prep
%setup -q

%build
%cmake
%cmake_build

%install
%cmakeinstall_std

%files
%_bindir/*

%changelog
* Thu Jun 08 2023 Anton Protopopov <antpro@basealt.ru> 0.1.0-alt1
- 


