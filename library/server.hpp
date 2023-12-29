//
// Created by JanHe on 29.12.2023.
//

#ifndef LIBMUMBLE_SERVER_SERVER_HPP
#define LIBMUMBLE_SERVER_SERVER_HPP

#pragma once

#include "mumble_server_export.h"
#include "pimpl.hpp"

#include <memory>

namespace libmumble::server {

class MUMBLE_SERVER_EXPORT ServerModel {};

class MUMBLE_SERVER_EXPORT EmbeddedServer {
   public:
	EmbeddedServer();
	virtual ~EmbeddedServer();
   private:
	struct Impl;
	DECLARE_PIMPL(Impl) m_pimpl;
};

}// namespace libmumble::server

#endif//LIBMUMBLE_SERVER_SERVER_HPP
